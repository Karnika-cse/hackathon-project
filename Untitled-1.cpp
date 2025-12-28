#include <crow.h>
#include <map>
#include <string>

int main() {
    crow::SimpleApp app;

    // Data Engine: Mapping Merchant Category Codes (MCC) to CO2 coefficients
    std::map<std::string, double> emission_factors = {
        {"Food", 2.5},      // kg CO2 per $
        {"Travel", 1.2},    // kg CO2 per mile/unit
        {"Utilities", 0.8}, // kg CO2 per unit
        {"Shopping", 1.5}   // kg CO2 per $
    };

    // Transaction Processing Route
    CROW_ROUTE(app, "/api/calculate").methods("POST"_method)
    ([&emission_factors](const crow::request& req) {
        auto x = crow::json::load(req.body);
        if (!x) return crow::response(400);

        double amount = x["amount"].d();
        std::string category = x["category"].s();
        
        // Automated Estimation Engine
        double co2_output = amount * (emission_factors.count(category) ? emission_factors[category] : 1.0);

        crow::json::wvalue res;
        res["co2"] = co2_output;
        res["relatable_metric"] = "Equivalent to " + std::to_string((int)(co2_output * 0.5)) + " tree seedlings grown for 10 years"; //
        
        return crow::response(res);
    });

    app.port(18080).multithreaded().run();
}