var isBalanced = function (root) {

    let flag = true;

    const get_heights = (node, height) => {

        if (!node) {//
            return 0;

        }

        const left_height  = get_heights(node.left, height + 1);
        const right_height = get_heights(node.right, height + 1);
        if (Math.abs(right_height - left_height) > 1) {
            flag = false;
        }
        return Math.max(left_height, right_height) + 1;
    };

    get_heights(root, 0);

    return flag;
};
