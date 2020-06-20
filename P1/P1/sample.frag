#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
//#extension GL_ARB_seperate_shader_objects : enable

varying vec3 vNormal;
varying vec2 vTexPosition;
varying vec3 vFragPos;

layout(location = 0) out vec4 fragColor;

layout(location = 5) uniform vec3 uColor;
layout(location = 6) uniform sampler2D uTex0;
// Phong
layout (location = 8) uniform vec3 uViewPosition;
layout (location = 9) uniform vec3 uLightPosition;
layout (location = 10) uniform float uKa; // Ambient
layout (location = 11) uniform float uKd; // Difuse
layout (location = 12) uniform float uKs; // Specular
layout (location = 13) uniform float uShininess;

vec3 calcPhongLight (vec3 viewDirection, vec3 lightDirection)
{
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 norm = normalize(vNormal);
    vec3 jadeAmb = vec3(0.135f, 0.2225f, 0.1575f);
    vec3 jadeDiff = vec3(0.54f, 0.89f, 0.63f);
    vec3 jadeSpec = vec3(0.316228f, 0.316228f, 0.316228f);
    // ambient
    float ambientStrength = 0.50;
    vec3 ambient = ambientStrength * lightColor * jadeAmb;

     // diffuse
    float diff = max(dot(norm, lightDirection), 0.0);
    vec3 diffuse = diff * lightColor * jadeDiff;

    // specular
    float specularStrength = 10.0;
    vec3 reflectDir = reflect(-lightDirection, norm);
    float spec = pow(max(dot(viewDirection, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor * jadeSpec;
    // attenuation
    // R        C       L       Q
    // 325, 1.0, 0.014, 0.0007
    float reflectLength = length(reflectDir);
    float viewLength = length(viewDirection);
    float d = distance(norm, uViewPosition);
    float att = 1.0f / (1.0f + (0.014 * d) + (0.0007 * pow(d,2)));
    return (ambient + diffuse + specular) * att;
}

void main()
{
    vec3 lightPos = vec3(uViewPosition * uLightPosition);
    vec3 result = calcPhongLight(normalize(uViewPosition - vFragPos), normalize(lightPos - vFragPos));
    fragColor = vec4(result * uColor, 1.0);
}
