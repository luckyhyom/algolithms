function mySolution(word, word2) {
    if (word.length !== word2.length) {
        return 'NO'
    }

    const a = {};
    const b = {};

    for (let i = 0; i < word.length; i++) {
        a[word[i]] = add(a[word[i]]);
        b[word2[i]] = add(b[word2[i]]);
    }

    for (const key in a) {
        if (a[key] !== b[key]) {
            return 'NO'
        }
    }

    return 'YES';
}

function add(value) {
    return value === undefined ? 1 : value += 1;
}

let word = 'AbaAeCe';
let word2 = 'baeeACA';

console.log(mySolution(word,word2));