class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int[] left = new int[26];
        Arrays.fill(left, -1);
        int[] right = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            final int c = s.charAt(i) - 'a';
            if (left[c] < 0) {
                left[c] = i;
            }
            right[c] = i;
        }
        LinkedList<String> r = new LinkedList<>();
        for (int i = 0, last = -1; i < s.length(); ++i) {
            final int c = s.charAt(i) - 'a';
            if (left[c] != i) {
                continue;
            }
            int end = right[c];
            for (int j = i + 1; j <= end; ++j) {
                final int temp = s.charAt(j) - 'a';
                end = left[temp] >= i ? Math.max(end, right[temp]) : -1;
            }
            if (end >= 0) {
                if (last >= i) {
                    r.removeLast();
                    
                }
                r.add(s.substring(i, end + 1));
                last = end;
                
            }
            
        }
        return r;
    }
}