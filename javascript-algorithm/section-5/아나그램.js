function mySolution(word, word2) {

    if (word.length !== word2.length) {
        return 'NO'
    }

    const a = {};
    const b = {};

    for (let i = 0; i < word.length; i++) {
        if (a[word[i]] === undefined) {
            a[word[i]] = 1;
            console.log(a[word[i]]);
        } else {
            a[word[i]]++;
        }

        if (b[word2[i]] === undefined) {
            b[word2[i]] = 1;
        } else {
            b[word2[i]]++;
        }
    }

    for (const key in a) {
        if (a[key] !== b[key]) {
            return 'NO'
        }
    }

    return 'YES';
}

let word = 'AbaAeCe';
let word2 = 'baeeACA';

console.log(mySolution(word,word2));