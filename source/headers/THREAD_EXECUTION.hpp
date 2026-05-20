#pragma once
#include "./global/hcp.hpp"
namespace TaskManagmentThreading {
    class ThreadInstancingOperation {
        private:

        public:
            bool ThreadTskInitialized = ((bool) 0.0F);
            /// @brief 
            /// @return 
            ThreadInstancingOperation();
            const std::optional<int> InitializeThread();
    };

    // class ThreadInstance : ThreadInstancingOperation {
    //     public:
            
    // };
}
