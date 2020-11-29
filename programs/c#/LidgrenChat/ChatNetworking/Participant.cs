using Lidgren.Network;

namespace ChatNetworking
{
    public class Participant
    {
        public string           Name        { get; set; }
        public NetConnection    Connection  { get; set; }

        public Participant()
        {

        }

        public Participant(string _name, NetConnection _connection)
        {
            Name        = _name;
            Connection  = _connection;
        }
    }
}
