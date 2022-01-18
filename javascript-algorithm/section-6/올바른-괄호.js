function mySolution(parentheses) {
    let status = 0;

    if ((parentheses.length % 2) !== 0) return 'NO';

    for (const p of parentheses) {
        if (p === '(') status++
        else status--;

        if (status === -1 ) return 'NO';
    }

    if (status !== 0) return 'NO';
    
    return 'YES';
}

const input = '()())('
console.log(mySolution(input));