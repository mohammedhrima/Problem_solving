function convertToTitle(columnNumber: number): string {
  let res: string = "";
  while (columnNumber > 0) {
    columnNumber--;
    let charcode: number = (columnNumber % 26) + 65;
    res = String.fromCharCode(charcode) + res;
    columnNumber = Math.floor(columnNumber / 26);
  }
  return res;
}
