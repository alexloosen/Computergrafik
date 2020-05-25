#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
//#extension GL_ARB_seperate_shader_objects : enable

in vec3 vColor;
in vec2 vTexPosition;

layout(location = 0) out vec4 fragColor;

layout(location = 5) uniform float time;
layout(location = 6) uniform sampler2D uTex0;

vec2 sinus(vec2 p)
{
    // Wellen-Verzerrung
    float x = sin( 10.0*p.y + 15.0*p.x + 10 * time) * 0.015;
    float y = sin( 10.0*p.y + 15.0*p.x + 10 * time) * 0.015;
    return vec2(p.x + x, p.y + y);
}

void main()
{
    fragColor = texture(uTex0, vTexPosition);
//    vec4 textureColor = texture(uTex0, sinus(vTexPosition));
//    fragColor = vec4(textureColor.r + cos(time) * 0.1, textureColor.g + cos(time) * 0.01, textureColor.b + cos(time) * 0.2 + 0.35, textureColor.a);
}
