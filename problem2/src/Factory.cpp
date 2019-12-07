//
// Created by davo1 on 03.12.2019.
//

#include "Factory.h"



//прям как в лекции :)

#include <map>
#include <vector>
#include <string>


class TFunctionFactory::TImpl {
    class ICreator {
    public:
        virtual ~ICreator() {}
        virtual TFunctionPtr Create(const TOptions& opts) const = 0;
    };

    using TCreatorPtr = std::shared_ptr<ICreator>;
    using TRegisteredCreators = std::map<std::string, TCreatorPtr>;

    TRegisteredCreators RegisteredCreators;
public:
    template<class TCurrentObject>
    class TCreator : public ICreator {
        TFunctionPtr Create(const TOptions& opts)  const override {
            return std::make_shared<TCurrentObject>(opts);
        }
    };
    TImpl() { RegisterAll();}
    template <typename T>
    void RegisterCreator(const std::string& name) {
        RegisteredCreators[name] = std::make_shared<TCreator<T>>();
    }
    void RegisterAll() {
        RegisterCreator<TIdent>("ident");
        RegisterCreator<TConst>("const");
        RegisterCreator<TPower>("power");
        RegisterCreator<TExp>("exp");
        RegisterCreator<TPolynomial>("polynomial");
    }

    TFunctionPtr CreateObject(const std::string& n, const TOptions& opts) const {
        auto creator = RegisteredCreators.find(n);
        if (creator == RegisteredCreators.end()) {
            return nullptr;
        }
        return creator->second->Create(opts);
    }


    std::vector<std::string> GetAvailableObjects () const {
        std::vector<std::string> result;
        for (const auto& creatorPair : RegisteredCreators) {
            result.push_back(creatorPair.first);
        }
        return result;
    }
};


TFunctionPtr TFunctionFactory::CreateObject(const std::string& type, const TOptions& opts  ) const {
    return Impl->CreateObject(type, opts);
}


TFunctionFactory::TFunctionFactory() : Impl(std::make_unique<TFunctionFactory::TImpl>()) {}
TFunctionFactory::~TFunctionFactory(){}
std::vector<std::string> TFunctionFactory::GetAvailableObjects() const {
    return Impl->GetAvailableObjects();
}

