template<class Type> class vehicle_handler
{
    public:
        vehicle_handler(Type _vehicle);
        ~vehicle_handler();

        void describe(void);

        Type m_vehicle;
};
