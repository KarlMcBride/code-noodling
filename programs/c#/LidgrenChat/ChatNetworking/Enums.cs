namespace ChatNetworking
{
    public enum PacketTypes
    {
        LOGIN,
        NOTIFY_CLIENTS_OF_UPDATED_PARTICIPANT_LIST,
        NOTIFY_CLIENTS_OF_NEW_MESSAGE,
        /// <summary>
        /// Disconnect message type sent when user disconnects cleanly (i.e. closing app through UI).
        /// Differentiated from disconnect due to timeout, which is purely handled server-side.
        /// </summary>
        CLIENT_DISCONNECTING
    }

    public enum DisconnectReason
    {
        Timeout,
        UserDisconnect
    };
}
