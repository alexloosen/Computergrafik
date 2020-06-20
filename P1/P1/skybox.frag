#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_seperate_shader_objects : enable

in vec3 vCubeDir;
out vec4 fragColor;
layout (location = 2) uniform samplerCube uCubeMap;
void main(void)
{
    fragColor = texture(uCubeMap, vCubeDir);
}
