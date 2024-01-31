#version 330 core

in vec2 tex_coord;

uniform sampler2D texture_id;
uniform vec2 sprite_pos = vec2(0, 0);
uniform vec2 spritesheet_dim = vec2(4, 1);

out vec4 frag_colour;

void main() {

    vec2 sample_coord = vec2(
        (tex_coord.x + sprite_pos.x)/spritesheet_dim.x, 
        (tex_coord.y + sprite_pos.y)/spritesheet_dim.y
    );

    frag_colour = texture(texture_id, sample_coord);
}