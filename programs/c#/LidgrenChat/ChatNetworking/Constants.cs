using Lidgren.Network;

namespace ChatNetworking
{
    /// <summary>
    /// Constants used across both client and server classes.
    /// </summary>
    public class SharedConstants
    {
        public const string APP_IDENTIFIER          = "LidgrenChat";
        public const string LOCAL_HOST_IP           = "127.0.0.1";
        public const int    HOST_PORT               = 14242;

        /// <summary>
        ///  Delay used to reduce CPU load by both client and server processes.
        /// </summary>
        public const int    MAIN_LOOP_DELAY_MS      = 500;

        /// <summary>
        /// Controls how long a connection can receive nothing before it times out and disconnects.
        /// Connection timeout must be equal to or greater than ping timeout (Lidgren check).
        /// </summary>
        public const float CONNECTION_TIMEOUT_SECONDS   = 5f;
        public const float PING_INTERVAL_SECONDS        = 2.5f;

        public const NetDeliveryMethod DELIVERY_METHOD  = NetDeliveryMethod.ReliableOrdered;
    }

    /// <summary>
    /// Constants intended for use by server class.
    /// </summary>
    public class ServerConstants
    {
        public const int SEQUENCE_CHANNEL              = 0;
    }
}
