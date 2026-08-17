    #include <bits/stdc++.h>
    using namespace std;

    class BkashPayment{
        public: void PayByBkash(float amount) {
            cout << "Pay By Bkash : " << amount;
        }
    };

    class NagadPayment{
        public: void PayByNagad(float amount) {
            cout << "Pay By Nagad : " << amount;
        }
    };

    //=================================================

    class PaymentGateway{
        public: virtual void DoPayment(float amount) {}
    };

    class BkashPaymentAdapter : public PaymentGateway{
        private: BkashPayment paymentProvider;

        public: void DoPayment(float amount){
            paymentProvider.PayByBkash(amount);
        }
    };

    class NagadPaymentAdapter : public PaymentGateway{
        private: NagadPayment paymentProvider;

        public: void DoPayment(float amount) {
            paymentProvider.PayByNagad(amount);
        }
    };

    //=================================================

    int main(){
        PaymentGateway *universal_payment_gateway;
        // Selected at runtime
        universal_payment_gateway = new NagadPaymentAdapter();
        universal_payment_gateway->DoPayment(100);

        return 0;
    }
