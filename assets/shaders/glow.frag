uniform sampler2D texture;
uniform vec4 glowColor;
uniform float glowSize;

void main() {
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    float dist = distance(gl_TexCoord[0].xy, vec2(0.5, 0.5));
    vec4 glow = glowColor * smoothstep(0.5, 0.5 + glowSize, dist); // Adjusted here
    gl_FragColor = pixel + glow;
}
