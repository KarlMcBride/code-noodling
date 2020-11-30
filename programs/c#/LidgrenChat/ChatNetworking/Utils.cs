using System;
using System.Net;
using System.Net.Sockets;

namespace ChatNetworking
{
    public static class Utils
    {
        public static string GetLanIpAddress()
        {
            string localIP = "No connection";
            try
            {
                Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.IP);
                socket.Connect("172.0.0.1", 65530);
                IPEndPoint endPoint = socket.LocalEndPoint as IPEndPoint;
                localIP = endPoint.Address.ToString();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            return localIP;
        }

        public static string GetPublicIpAddress()
        {
            string ipAddress = "No connection";
            try
            {
                WebClient client = new WebClient();
                ipAddress = client.DownloadString("http://ifconfig.me").Replace("\n", "");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            return ipAddress;
        }
    }
}
