class Solution {
    public boolean detectCapitalUse(String word) {
        boolean allcap = true, alllower = true, caplower = true;
        for(int i=0; i<word.length(); i++) {
            char c = word.charAt(i);
            if(Character.isLowerCase(c)) allcap = false;
            if(Character.isUpperCase(c)) alllower = false;
            if(i == 0 && Character.isLowerCase(c) || i != 0 && Character.isUpperCase(c)) caplower = false;
        }

        return allcap || alllower || caplower;
    }
}