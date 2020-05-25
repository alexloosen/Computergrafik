#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
//#extension GL_ARB_seperate_shader_objects : enable

in vec3 vColor;

out vec4 fragColor;

layout(location = 0) uniform float uAlpha;

void main()
{
    fragColor = vec4(vColor, uAlpha);
}
