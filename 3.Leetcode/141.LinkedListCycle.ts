// Definition for singly-linked list.
class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function hasCycle(head: ListNode | null): boolean {
  let found = false;
  let set = new Set();
  while (head) {
    if (set.has(head)) {
      found = true;
      break;
    }
    set.add(head);
    head = head.next;
  }
  return found;
}
