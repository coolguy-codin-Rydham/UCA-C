import express from "express";
const app = express();

app.use("/", express.static("./static"));

app.listen(8080, () => {
    console.log(`Server working on http://localhost:8080`);
});



