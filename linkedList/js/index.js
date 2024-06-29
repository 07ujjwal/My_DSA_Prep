console.log("console");

class Node {
  constructor(data, next) {
    this.data = data;
    this.next = next;
  }
}

class ListFunctions {
  convertArrToLL(arr) {
    let head = new Node(arr[0]);
    let current = head;

    for (let i = 1; i < arr.length; i++) {
      let temp = new Node(arr[i]);
      current.next = temp;
      current = temp;
    }

    return head;
  }

  printLL(head) {
    let current = head;
    while (current) {
      console.log(current?.data);
      current = current?.next;
    }
  }

  deleteHead(head) {
    if (head === 0) {
      return head;
    }

    let temp = head;
    head = head.next;
    temp = null;

    return head;
  }

  deleteTail(head) {
    if (head === null) {
      return null;
    }

    if (head.next === null) {
      head = null;
      return null;
    }

    let temp = head;
    while (temp.next !== null && temp.next.next !== null) {
      temp = temp.next;
    }

    temp.next = null;
    return head;
  }
}

const y = new Node(2, null);
const listFunctions = new ListFunctions();

const arr = [1, 2, 3, 4, 5];

console.log(y.data);

let head = listFunctions.convertArrToLL(arr);

listFunctions.printLL(head);

head = listFunctions.deleteTail(head);

listFunctions.printLL(head);

const data = [
  {
    id: 1,
    propertyId: 2,
    firstAid: true,
    visitingDoctor: false,
  },
  {
    id: 4,
    propertyId: 2,
    firstAid: false,
    visitingDoctor: false,
  },
  {
    id: 5,
    propertyId: 2,
    firstAid: false,
    visitingDoctor: false,
  },
];

const requiredData = [
  "id - 1",
  "propertyId - 2",
  "firstAid - false",
  "visitingDoctor - false",
];

const convertArray = (data) => {
  const requiredData = [];

  const firstObject = data[0];
  for (const key in firstObject) {
    if (Object.hasOwnProperty.call(firstObject, key) && key !== "id") {
      let value = firstObject[key];
      if (value === true) {
        value = "yes";
      } else if (value === false || value === null) {
        value = "no";
      }
      requiredData.push(`${key} - ${value}`);
    }
  }

  return requiredData;
};

const newObject = convertArray(data);

console.log(newObject);
