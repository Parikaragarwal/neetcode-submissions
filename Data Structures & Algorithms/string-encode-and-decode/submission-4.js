class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
      const count = String(strs.length);
      strs.push(count);
      return strs.join('01010101010101010001');
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
      const ans = str.split('01010101010101010001')
      const count = Number(ans.pop());
      if(count===0){
        return [];
      }
     return ans;
    }
}
