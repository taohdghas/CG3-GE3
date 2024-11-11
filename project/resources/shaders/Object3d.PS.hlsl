#include "Object3d.hlsli"

struct Material
{
    float32_t4 color;
    int32_t enableLighting;
    float32_t4x4 uvTransform;
};
struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
};
struct DirectionalLight
{
    float32_t4 color;//ライトの色
    float32_t3 direction;//ライトの向き
    float intensity;//輝度
};
ConstantBuffer<Material> gMaterial : register(b0);
ConstantBuffer<DirectionalLight> gDirectionalLight : register(b1);
Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);

PixelShaderOutput main(VertexShaderOutput input)
{
    PixelShaderOutput output;
    output.color = gMaterial.color;
    float4 transformedUV = mul(float32_t4(input.texcoord,0.0f,1.0f), gMaterial.uvTransform);
    float32_t4 textureColor = gTexture.Sample(gSampler,transformedUV.xy);
   
    if (gMaterial.enableLighting != 0)//Lightingする場合
    {
        float NdotL = dot(normalize(input.normal), -gDirectionalLight.direction);
        float cos = pow(NdotL * 0.5f + 0.5f, 2.0f);
        output.color = gMaterial.color * textureColor * gDirectionalLight.color * cos * gDirectionalLight.intensity;
    }
    else//Lightingしない場合。前回と同じ演算
    {
        output.color = gMaterial.color * textureColor;
    }
    return output;
}
