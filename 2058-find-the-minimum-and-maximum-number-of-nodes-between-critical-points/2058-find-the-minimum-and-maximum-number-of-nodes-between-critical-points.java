class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        if (head == null) {
            return new int[]{-1, -1};
        }

        ListNode prev = head;
        ListNode curr = head.next;
        int i = 1;

        List<Integer> criticalPoints = new ArrayList<>();

        while (curr != null && curr.next != null) {
            // compare for maxima
            if (curr.val > prev.val && curr.val > curr.next.val) {
                criticalPoints.add(i);
            }
            // compare for local minima
            if (curr.val < prev.val && curr.val < curr.next.val) {
                criticalPoints.add(i);
            }
            curr = curr.next;
            prev = prev.next;
            i = i + 1;
        }

        if (criticalPoints.size() < 2) {
            return new int[]{-1, -1};
        }

        // critical points ki list ready hogi
        int minDist = Integer.MAX_VALUE;

        for (int j = 1; j < criticalPoints.size(); j++) {
            minDist = Math.min(minDist, criticalPoints.get(j) - criticalPoints.get(j - 1));
        }

        int maxDist = criticalPoints.get(criticalPoints.size() - 1) - criticalPoints.get(0);

        return new int[]{minDist, maxDist};
    }
}