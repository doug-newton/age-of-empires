#version 330 core

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec2 texture_coord;

out vec2 tex_coord;

void main() {
    gl_Position = vec4(vertex_position.x, vertex_position.y, vertex_position.z, 1.0);
}