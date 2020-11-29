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

    public class ParticipantMessage
    {
        public string Sender    { get; set; }
        public string Message   { get; set; }

        public ParticipantMessage()
        {

        }

        public ParticipantMessage(string _sender, string _message)
        {
            Sender  = _sender;
            Message = _message;
        }
    }
}
