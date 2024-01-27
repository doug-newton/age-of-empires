#version 330 core

in vec2 tex_coord;

uniform sampler2D texture_id;

out vec4 frag_colour;

void main() {
    frag_colour = texture(texture_id, tex_coord);
}