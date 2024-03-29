#version 330 core

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec4 vertex_colour;

out vec4 colour;

void main() {
    colour = vertex_colour;
    gl_Position = vec4(vertex_position.x, vertex_position.y, vertex_position.z, 1.0);
}