function calculate() {
    let amount = document.getElementById("amount").value;
    let category = document.getElementById("category").value;
    let emission = 0;
    let suggestion = "";

    if (category === "food") {
        emission = amount * 0.02;
        suggestion = "Reduce food waste and prefer local produce.";
    } 
    else if (category === "travel") {
        emission = amount * 0.05;
        suggestion = "Use public transport to reduce emissions.";
    } 
    else if (category === "shopping") {
        emission = amount * 0.03;
        suggestion = "Buy sustainable and reusable products.";
    }

    document.getElementById("result").innerHTML =
        "<h3>Estimated Carbon Footprint</h3>" +
        "<p>" + emission.toFixed(2) + " kg CO₂</p>" +
        "<p><b>Suggestion:</b> " + suggestion + "</p>";
}

