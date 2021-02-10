## 位运算

- [268 丢失的数字](https://leetcode-cn.com/problems/missing-number/)
- [231 2的幂](https://leetcode-cn.com/problems/power-of-two/)
- [191 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)
- [190 颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)
- [338 比特位计数](https://leetcode-cn.com/problems/counting-bits/)
- [169 多数元素](https://leetcode-cn.com/problems/majority-element/)

## 数组

- [283 移动零](https://leetcode-cn.com/problems/move-zeroes/)
- [11 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)
- [485 最大连续1的个数](https://leetcode-cn.com/problems/max-consecutive-ones/)
- [26 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)
- [88 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)
- [66 加一](https://leetcode-cn.com/problems/plus-one/)
- [167 两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)
- [15 三数之和](https://leetcode-cn.com/problems/3sum/)
- [189 旋转数组](https://leetcode-cn.com/problems/rotate-array/)
- [42 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)

## 链表

- [21 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)
- [206 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)
- [24 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)
- [141 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)
- [25 K个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)
- [430 扁平化多级双向链表](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/)

## 栈 队列

- [20 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)
- [641 设计循环双端队列](https://leetcode-cn.com/problems/design-circular-deque/)
- [155 最小栈](https://leetcode-cn.com/problems/min-stack/)
- [84 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)

  ```思路
  #### 解法一
  先找到最小的元素，再从分成两部分分治
  超时了！！！
  优化，可以比较左右两段的最小值，不需要循环找最小值
  ####
  
  #### 解法二
  利用栈，保存元素索引，保持栈为单调递增
  可以根据索引可以计算距离即宽度
  ####
  ```

- [239 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)

  ```思路
  #### 解法
  用双端队列，每追加一个元素，去除比该元素小的元素，同时去掉不在窗口的元素
  用C写的执行时间远大于用JAVA写的执行时间，自己数组实现的双端队列，执行效率很差！！！
  ####
  ```

## 树 递归 分治 回溯

- [2 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)
- [897 递增顺序查找树](https://leetcode-cn.com/problems/increasing-order-search-tree/)
- [938 二叉搜索树的范围和](https://leetcode-cn.com/problems/range-sum-of-bst/)
- [1137 第N个泰波那契数](https://leetcode-cn.com/problems/n-th-tribonacci-number/)
- [783 二叉搜索树节点最小距离](https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/)
- [110 平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)
- [563 二叉树的坡度](https://leetcode-cn.com/problems/binary-tree-tilt/)
- [104 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)
- [1379 找出克隆二叉树中的相同节点](https://leetcode-cn.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)
- [894 所有可能的满二叉树](https://leetcode-cn.com/problems/all-possible-full-binary-trees/)
- [589 N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/)
- [590 N叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/)
- [429 N叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)
- [144 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)
- [94 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)
- [102 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
- [515 在每个树行中找最大值](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/)
- [22 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)
- [669 修剪二叉搜索树](https://leetcode-cn.com/problems/trim-a-binary-search-tree/)
- [865 具有所有最深节点的最小子树](https://leetcode-cn.com/problems/smallest-subtree-with-all-the-deepest-nodes/)
- [1306 跳跃游戏 III](https://leetcode-cn.com/problems/jump-game-iii/)
- [538 1038 把二叉搜索树转换为累加树](https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/)
- [17 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)
- [1718 构建字典序最大的可行序列](https://leetcode-cn.com/problems/construct-the-lexicographically-largest-valid-sequence/)
- [395 至少有K个重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/)
- [779 第K个语法符号](https://leetcode-cn.com/problems/k-th-symbol-in-grammar/)
- [687 最长同值路径](https://leetcode-cn.com/problems/longest-univalue-path/)
- [967 连续差相同的数字](https://leetcode-cn.com/problems/numbers-with-same-consecutive-differences/)
- [98 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)
- [794 有效的井字游戏](https://leetcode-cn.com/problems/valid-tic-tac-toe-state/)
- [124 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)
- [617 合并二叉树](https://leetcode-cn.com/problems/merge-two-binary-trees/)
- [226 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)
- [700 二叉搜索树中的搜索](https://leetcode-cn.com/problems/search-in-a-binary-search-tree/)
- [108 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)
- [559 N叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/)
- [1022 从根到叶的二进制数之和](https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/)
- [637 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/)
- [965 单值二叉树](https://leetcode-cn.com/problems/univalued-binary-tree/)
- [107 二叉树的层序遍历II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)
- [257 二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/)
- [235 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
- [872 叶子相似的树](https://leetcode-cn.com/problems/leaf-similar-trees/)
- [530 二叉搜索树的最小绝对差](https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/)
- [100 相同的树](https://leetcode-cn.com/problems/same-tree/)
- [653 两数之和IV-输入BST](https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/)
- [404 左叶子之和](https://leetcode-cn.com/problems/sum-of-left-leaves/)
- [606 根据二叉树创建字符串](https://leetcode-cn.com/problems/construct-string-from-binary-tree/)
- [101 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)
- [993 二叉树的堂兄弟节点](https://leetcode-cn.com/problems/cousins-in-binary-tree/)
- [543 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)
- [112 路径总和](https://leetcode-cn.com/problems/path-sum/)
- [501 二叉搜索树中的众数](https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/)
- [572 另一个树的子树](https://leetcode-cn.com/problems/subtree-of-another-tree/)
- [111 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)
- [671 二叉树中第二小的节点](https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/)
- [654 最大二叉树](https://leetcode-cn.com/problems/minesweeper/)
- [1302 层数最深叶子节点的和](https://leetcode-cn.com/problems/deepest-leaves-sum/)
- [1315 祖父节点值为偶数的节点和](https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent/)
- [222 完全二叉树的节点个数](https://leetcode-cn.com/problems/count-complete-tree-nodes/)
- [173 二叉搜索树迭代器](https://leetcode-cn.com/problems/binary-search-tree-iterator/)
- [1305 两棵二叉搜索树中的所有元素](https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/)
- [145 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)
- [1325 删除给定值的叶子节点](https://leetcode-cn.com/problems/delete-leaves-with-a-given-value/)
- [1261 在受污染的二叉树中查找元素](https://leetcode-cn.com/problems/find-elements-in-a-contaminated-binary-tree/)
- [230 二叉搜索树中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/)
- [1008 前序遍历构造二叉搜索树](https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/)
- [513 找树左下角的值](https://leetcode-cn.com/problems/find-bottom-left-tree-value/)
- [701 二叉搜索树中的插入操作](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)
- [114 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)
- [1104 二叉树寻路](https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/)
- [529 扫雷游戏](https://leetcode-cn.com/problems/minesweeper/)
- [433 最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)
- [127 单词接龙](https://leetcode-cn.com/problems/word-ladder/)
- [126 单词接龙 II](https://leetcode-cn.com/problems/word-ladder-ii/)
- [98 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)
- [297 二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)
- [236 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)
- [105 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
- [77 组合](https://leetcode-cn.com/problems/combinations/)
- [46 全排列](https://leetcode-cn.com/problems/permutations/)
- [47 全排列 II](https://leetcode-cn.com/problems/permutations/)
- [50 Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)
- [78 子集](https://leetcode-cn.com/problems/powx-n/)

## HashTable

- [hashtable操作](hashtable.md)

- [1 两数之和](https://leetcode-cn.com/problems/two-sum/description/)

  ```思路
  #### 解法
  暴力循环
  排序后左右夹逼
  两遍哈希
  一遍哈希
  ####
  ```

- [242 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/description/)
- [49 字母异位词分组](https://leetcode-cn.com/problems/valid-anagram/description/)

## 排序

- [插入排序](insertSort.md)
- [归并排序](mergeSort.md)