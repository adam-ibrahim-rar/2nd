// Write a TypeScript program that accepts an array of words and returns a new array
// containing only the words that do not contain repeated characters.
let inp = document.getElementById("myinput3") as HTMLInputElement
let btt = document.getElementById("btn3") as HTMLButtonElement
let txt3 = document.getElementById("txt3") as HTMLHeadingElement
function frist(array: string[]): string[] {
  let newarray: string[] = [];

  for (let i = 0; i < array.length; i++) {
    let myElement = array[i] as string;
    let ok = true;

    for (let j = 0; j < myElement.length; j++) {
      let mychar = myElement[j];
      let count = 0;
      for (let k = 0; k < myElement.length; k++) {
        if (myElement[k] == mychar && k != j) count++;
      }
      if (count > 0) ok = false;
    }

    if (ok) newarray.push(myElement);
  }

  return newarray;
}
btt.addEventListener("click", () => {
  let arrr: string[] = inp.value.split("-")
  let myst = frist(arrr).join("-")
  txt3.innerText = myst;
  inp.value=" "
})
// ----------------------------------
// Write a TypeScript program that processes a string input and produces a string output
// according to the following rule: keep all characters at the odd positions unchanged and
// swap each two characters at consecutive even positions (i.e., position 0 with 2, position 4
// with 6, etc.). For example, if the input string is “abcdefghi”, then the expected output
// should be “cbadgfehi”.
let inp2 = document.getElementById("myinput2") as HTMLInputElement
let btt2 = document.getElementById("btn2") as HTMLButtonElement
let txt2 = document.getElementById("txt2") as HTMLHeadingElement
let mystr1 = "abcdefghi";
function myfun(input: string): string {
  let tempStr: string = "";
  let array = input.split("");
  let newarr: string[] = [];
  for (let i = 0; i < array.length; i++) {
    let mychar = array[i] as string;
    if (i % 2 != 0) newarr[i] = mychar;
  }
  for (let i = 0; i < array.length; i++) {
    let mychar = array[i] as string;
    let myNextChar = array[i + 2] as string;
    if (i % 2 == 0) {
      newarr[i] = myNextChar;
      newarr[i + 2] = mychar;
      i += 2;
    }
  }
  tempStr = newarr.toString();
  //   البرنامج بيطلع فواصل باين سببها ان الi+2 بيعدي الlength ف بيحط , وكده ف الجزء ده عشان احذف ال,
  let output: string = "";
  for (let i = 0; i < tempStr.length; i++) {
    if (tempStr[i] != ",") {
      output += tempStr[i];
    }
  }
  return output;
}
btt2.addEventListener("click", () => {
  let string: string = inp2.value
  txt2.innerText = myfun(string);
  inp2.value=" "
})

// ---------------------------------------------
// Write a TypeScript program that allows users to input a series of numbers separated by
// dashes in a text field (for example: 12-9-5). When the user clicks the “Show Primes”
// button, the program should perform the following tasks: (a) store the entered data in an
// array and (b) list the prime numbers from the array in a tabular format.
let myinput = document.getElementById("myinput") as HTMLInputElement;
let btn = document.getElementById("btn") as HTMLButtonElement;
let show1 = document.getElementById("txt") as HTMLHeadingElement;
btn.addEventListener("click", () => {
  let str: string = "";
  let myarr: string[] = [];
  let my_num_arr: number[] = [];
  str = myinput.value;
  myarr = str.split("-");
  for (let i = 0; i < myarr.length; i++) {
    let myelement = myarr[i] as string;
    my_num_arr.push(parseInt(myelement));
  }
  let temp = prime(my_num_arr);
  show1.innerText = temp.toString();
});
function prime(array: number[]): number[] {
  let arr: number[] = [];
  for (let i = 0; i < array.length; i++) {
    let myele = array[i] as number;
    let isPrime = true;
    for (let j = 2; j < myele; j++) {
      if (myele % j == 0) isPrime = false;
    }
    if (isPrime) arr.push(myele);
  }
  return arr;
}
// --------------------------
// Write a TypeScript program to create a simple calculator. A user should input two operand
// values using text fields. The program allows the following operations: addition, subtraction,
// multiplication, division, and remainder. These operations should be declared as methods in an
// interface named “MathOperations”. An object implementing that interface is used to
// perform the operations. When the user clicks the “Calculate” button, the program should
// display the results of all operations in a tabular format. The header row should be distinguished
// from others using colors. If the second operand is zero, an error message should be shown next
// to the text field indicating that zero is not allowed.
interface MathOperations {
  addition(num1: number, num2: number): number;
  subtraction(num1: number, num2: number): number;
  multiplication(num1: number, num2: number): number;
  division(num1: number, num2: number): number;
  remainder(num1: number, num2: number): number;
}
let perform: MathOperations = {
  addition(num1: number, num2: number): number {
    return num1 + num2;
  },
  subtraction(num1: number, num2: number): number {
    return num1 - num2;
  },
  multiplication(num1: number, num2: number): number {
    return num1 * num2;
  },
  division(num1: number, num2: number): number {
    return num1 / num2;
  },
  remainder(num1: number, num2: number): number {
    return num1 % num2;
  },
};
let my1st_num = document.getElementById("1st") as HTMLInputElement;
let my2nd_num = document.getElementById("2nd") as HTMLInputElement;
let show = document.getElementById("tablur") as HTMLHeadingElement;
let CalculateBtn = document.getElementById("Calculate") as HTMLButtonElement;

CalculateBtn.addEventListener("click", () => {
  let num1 = parseInt(my1st_num.value);
  let num2 = parseInt(my2nd_num.value);
  if (num2 == 0) {
    show.innerText = "zero is not allowed";
    show.style.color = "red";
    return;
  }
  show.innerHTML = `${perform.addition(num1, num2).toString()}<br>`;
  show.innerHTML += `${perform.subtraction(num1, num2).toString()}<br>`;
  show.innerHTML += `${perform.multiplication(num1, num2).toString()}<br>`;
  show.innerHTML += `${perform.division(num1, num2).toString()}<br>`;
  show.innerHTML += `${perform.remainder(num1, num2).toString()}<br>`;
});