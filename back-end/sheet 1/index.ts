// Write a TypeScript program that implements a simple calculator. Each of
// the following operations should be implemented using a function
// expression: addition, subtraction, multiplication, division, and remainder.
// Each function should accept at least two operands and at most three as
// inputs. The program should display the results of all operations.

let addition = function add(x: number, y: number) {
  return x + y;
};
let subtraction = function add(x: number, y: number) {
  return x - y;
};
let multiplication = function add(x: number, y: number) {
  return x * y;
};
let division = function add(x: number, y: number) {
  return x / y;
};
let remainder = function add(x: number, y: number) {
  return x % y;
};

console.log(addition(5, 7));
console.log(subtraction(5, 7));
console.log(multiplication(5, 7));
console.log(division(5, 7));
console.log(remainder(5, 7));

// -----------------------------------------------------------------------

// Write a TypeScript program that converts a temperature from Celsius to
// other units. It should provide options to convert the temperature to
// Fahrenheit, Kelvin, or both. The program should display the converted
// temperature(s) according to the user choice

let celsius: number = 10;
let fahrenheit: number = celsius * 1.8 + 32;
let kelvin: number = celsius + 273.15;
console.log(kelvin);
console.log(fahrenheit);

// -----------------------------------------------------------------------

// Write a TypeScript program to find the factors of a given number using an
// arrow function. Display the factors in a single line separated by a hyphen
// Also, display a message indicating the total number of factors.

let findFactors = (num: number): void => {
  let count: number = 0;
  let factors: number[] = [];

  for (let i = 1; i <= num; i++) {
    if (num % i === 0) {
      factors.push(i);
      count++;
    }
  }

  console.log(factors.join("-"));
  console.log("The total number of factors is " + count);
};

findFactors(50);

//----------------------------------------------------------------------

// Write a TypeScript program to define a function accepts an indefinite
// number of User type. Each User type should contain the following
// properties: id (number), name (string), email (string), and
// isSubscribed (boolean). The function should return the number of
// users who are subscribed.

type user = {
  id: number;
  name: string;
  email: string;
  isSubscribed: boolean;
};

function users(user: user[]): number {
  let count = 0;
  for (let i = 0; i < user.length; i++) {
    if ((user[i] as user).isSubscribed == true) {
      count++;
    }
  }
  return count;
}
