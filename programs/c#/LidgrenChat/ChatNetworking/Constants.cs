namespace ChatNetworking
{
    public class Constants
    {
        public const string APP_IDENTIFIER          = "LidgrenChat";
        public const string LOCAL_HOST_IP           = "127.0.0.1";
        public const int    HOST_PORT               = 14242;

        // Delay used to reduce CPU load by both client and server processes.
        public const int    MAIN_LOOP_DELAY_MS      = 500;
        public const int    CLIENT_INIT_RETRY_MS    = 500;
    }
}
