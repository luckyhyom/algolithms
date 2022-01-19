function mySolution(parentheses) {
    let stack = [];
    let answer = '';
    for (const x of parentheses) {
        if (x === '(') stack.push(x);
        if (stack.length === 0) answer += x;
        if (x === ')') stack.pop();
    }

    return answer;
}

console.log(mySolution('(A(BC)D)EF(G(H)(IJ)K)LM(N)'));