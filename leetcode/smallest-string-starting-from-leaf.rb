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