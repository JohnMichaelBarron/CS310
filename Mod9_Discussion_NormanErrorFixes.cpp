#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class DataProcessor {
public:
    virtual void process(const std::vector<std::string>& data) const = 0; //  Added semicolon
    virtual ~DataProcessor() {} // Moved to its own line
};

class CsvProcessor : public DataProcessor {
public:
    void process(const std::vector<std::string>& data) const override {
        for (const auto& row : data) {
            if (row.empty()) {
                throw std::runtime_error("Empty CSV row");
            }
        }
    }
};

class JsonProcessor : public DataProcessor {
public:
    void process(const std::vector<std::string>& data) const override { //  Use const reference to match base
        for (const auto& elem : data) {
            if (elem.empty() || elem.front() != '{') {
                throw std::invalid_argument("Invalid JSON element");
            }
        }
    }
};

class XmlProcessor : public DataProcessor {
public:
    void process(const std::vector<std::string>& data) const override {
        for (const auto& node : data) {
            if (node.find('<') == std::string::npos) {
                throw std::runtime_error("Malformed XML node"); //  Added missing semicolon
            }
        }
    }
};

int main() {
    std::vector<std::string> records = {
        "id,name,score",
        "{\"id\":1,\"name\":\"Alice\"}",
        "<record id='2'>Bob</record>"
    };

    std::unique_ptr<DataProcessor> csvProc = std::make_unique<CsvProcessor>();
    std::unique_ptr<DataProcessor> jsonProc(new JsonProcessor());
    std::unique_ptr<DataProcessor> xmlProc(new XmlProcessor()); //  Fixed extra parenthesis

    try {
        csvProc->process(records);
        jsonProc->process(records);
        xmlProc->process(records);
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
