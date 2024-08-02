const fun = () => {
  const div = document.getElementById("jsworld");

  div.innerHTML = `Hello World From JS`;
};

const data = [
  {
    Product: "Pav Bhaji",
    Detials: "Exotic Mumbai Style Pav Bhaji with lemon and onions",
    Price: 100,
  },
  {
    Product: "Dahi Wada",
    Detials: "Exotic South Style Dahi Wada with Sauce and pepper",
    Price: 110,
  },
  {
    Product: "Idli Sambar",
    Detials: "Light and Healty and its amazing",
    Price: 120,
  },
];

const initializeTable = () => {
  const table = document.getElementById("table");

  table.innerHTML = `
    <thead>
        <tr>
            <th>Sr.No</th>
            <th>Product Name</th>
            <th>Details</th>
            <th>Price</th>
        </tr>

    </thead>
    <tbody>
        ${data.map((item, index) => {
        return (
        `<tr>
            <td>${index + 1}</td>
            <td>${item.Product}</td>
            <td>${item.Detials}</td>
            <td>${item.Price}</td>
        </tr>`);
        })}
    </tbody>`;
};

fun();

initializeTable();

console.log("HGell");
