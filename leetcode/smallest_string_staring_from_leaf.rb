# https://leetcode.com/problems/smallest-string-starting-from-leaf/
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {String}
$dict = ('a'..'z').to_a 
def smallest_from_leaf(root)
    return "" if root.nil?
    func(root, nil, "")
end

def func(root, mstr, str)
    str = $dict[root.val] + str
    if (root.left.nil? && root.right.nil?)
        return mstr = mstr.nil? ? str : [str,mstr].min
    end
    mstr = func(root.left, mstr, str) unless root.left.nil?
    mstr = func(root.right, mstr, str) unless root.right.nil? 
    return mstr
end    