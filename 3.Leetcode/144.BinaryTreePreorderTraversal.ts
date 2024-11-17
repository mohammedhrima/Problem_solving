class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function feed(list: number[], node: TreeNode | null) {
  if (node) {
    list.push(node.val);
    feed(list, node.left);
    feed(list, node.right);
  }
}

function preorderTraversal(root: TreeNode | null): number[] {
  let list: number[] = [];
  feed(list, root);
  return list;
}
