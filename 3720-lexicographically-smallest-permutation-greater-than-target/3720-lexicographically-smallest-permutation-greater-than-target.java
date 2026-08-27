class Solution {

    private void make(StringBuilder r, int n, int[] have) {
        for (int i = 0; r.length() < n;) {
            if (have[i] > 0) {
                r.append((char) (i + 'a'));
                have[i]--;
            } else {
                i++;
            }
        }
    }

    public String lexGreaterPermutation(String s, String target) {
        int[] have = new int[26];
        for (char c : s.toCharArray()) {
            have[c - 'a']++;
        }

        StringBuilder r = new StringBuilder();
        for (char c : target.toCharArray()) {
            if (have[c - 'a'] > 0) {
                have[c - 'a']--;
                r.append(c);
            } else {
                break;
            }
        }

        int n = s.length();
        if (r.length() == n) {
            have[r.charAt(r.length() - 1) - 'a']++;
            r.deleteCharAt(r.length() - 1);
        }

        while (true) {
            int pos = r.length();
            boolean found = false;
            for (int i = target.charAt(pos) - 'a' + 1; i < 26; i++) {
                if (have[i] > 0) {
                    have[i]--;
                    r.append((char) (i + 'a'));
                    make(r, n, have);
                    return r.toString();
                }
            }
            if (r.length() == 0) return "";
            have[r.charAt(r.length() - 1) - 'a']++;
            r.deleteCharAt(r.length() - 1);
        }
    }
}