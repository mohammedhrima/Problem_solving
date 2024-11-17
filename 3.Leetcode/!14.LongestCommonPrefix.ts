// function longestCommonPrefix(strs: string[]): string {
//     let i = 0;
//     let j = 0;
//     let curr = strs[i][j];
//     let res = "";
    
//     while(i < strs.length)
//     {
//         if(strs[j] !== curr || strs[j] == '')
//             break;
//         if(i == strs.length)
//         {
//             res = res + String.from(strs[j]);
//             j++;
//             i = 0;
//         }
//         i++;
//     }
//     return res;
// };