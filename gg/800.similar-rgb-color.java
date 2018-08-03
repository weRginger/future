class Solution {
    public String similarRGB(String color) {
        int hex1 = Integer.parseInt(color.substring(1), 16);
        int ans = 0;
        for (int r = 0; r < 16; ++r)
            for (int g = 0; g < 16; ++g)
                for (int b = 0; b < 16; ++b) {
                    int hex2 = 17 * r * (1 << 16) + 17 * g * (1 << 8) + 17 * b;
                    if (similarity(hex1, hex2) > similarity(hex1, ans))
                        ans = hex2;
                }

        return String.format("#%06x", ans);
    }

    public int similarity(int hex1, int hex2) {
        int ans = 0;
        for (int shift = 16; shift >= 0; shift -= 8) {
            int col1 = (hex1 >> shift) % 256;
            int col2 = (hex2 >> shift) % 256;
            ans -= (col1 - col2) * (col1 - col2);
        }
        return ans;
    }
}

class Solution {
    public String similarRGB(String color) {
        return "#" + f(color.substring(1, 3)) + f(color.substring(3, 5)) + f(color.substring(5));
    }

    public String f(String comp) {
        int q = Integer.parseInt(comp, 16);
        q = q / 17 + (q % 17 > 8 ? 1 : 0);
        return String.format("%02x", 17 * q);
    }
}