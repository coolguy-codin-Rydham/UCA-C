// function init() {
//     document.getElementById("jsworld").innerHTML = "Hello World from JavaScript!";
// }

var randomArray = [1, 2, 3, 4, 5, 6];

var productsList=[];

function fetchProductList() {
  console.log("getProductList");
  productsList = [
    {
      name: "Product 1",
      description: "Some additional details about P1",
      price: 100,
    },
    {
      name: "Product 2",
      description: "Some additional details about P2",
      price: 200,
    },
  ];
  initProductItem();
  // return productsList;
}

function initProductItem() {
  console.log("Initializing Product Item");
  document.getElementById("productMenu").innerHTML = `
    <h3>List of Products</h3>
    <table>
            <thead>
                <tr>
                    <th>Serial No.</th>
                    <th>Product Name</th>
                    <th>Description</th>
                    <th>Price</th>
                </tr>
            </thead>
            <tbody>
                ${getProductListUsingMap()}
            </tbody>
        </table>
    `;
}

function getProductList() {
  var rows = "";
  for (let i = 0; i < productsList.length; i++) {
    rows =
      rows +
      `
        <tr>
        <td>${i + 1}</td>
        <td>"Dish 1"</td>
        <td>"Dist 1 Details</td>
        <td>20</td>
        </tr>`;
  }
  return rows;
}

function getProductListUsingMap() {
  var helper = productsList.map((item, i) => {
    return `
        <tr>
          <td>${i + 1}</td>
          <td>${item.name}</td>
          <td>${item.description}</td>
          <td>20</td>
        </tr> <br/>`;
  });

  return helper.join("");
}


setTimeout(fetchProductList, 2000)

// productsList= fetchProductList();
initProductItem();