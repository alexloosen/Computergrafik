#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
//#extension GL_ARB_seperate_shader_objects : enable

in vec2 vTexPosition;
in vec3 vNormal;
in vec3 vFragPos;

layout(location = 0) out vec4 fragColor;

layout(location = 3) uniform vec3 uColor;

void main()
{
    fragColor = vec4(uColor, 1.0);
}
