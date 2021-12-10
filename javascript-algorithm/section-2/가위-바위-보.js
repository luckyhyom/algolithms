function mjb(A, B) {
    let result = [];
    for (let i = 0; i < A.length; i++) {
        if (A[i] === 1 && B[i] === 2) {
            result.push('B');
            continue;
        }
        if (A[i] === 2 && B[i] === 3) {
            result.push('B');
            continue;
        }
        if (A[i] === 3 && B[i] === 1) {
            result.push('B');
            continue;
        }
        if (A[i] === B[i]) {
            result.push('D')
            continue;
        }
        result.push('A')
    }

    return result;
}

console.log((mjb([2,3,3,1,3], [1,1,2,2,3])));