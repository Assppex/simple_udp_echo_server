#include "main.hpp"

#define UDP_PORT 50'013
namespace asio = boost::asio;
namespace sys = boost::system;

class UdpServer
{
    public:
        void bind_socket_udp(asio::io_context& io)
        {
            this->socket = std::make_shared<asio::ip::udp::socket>(io,asio::ip::udp::endpoint(asio::ip::udp::v6(),UDP_PORT));

        }
        void start_listenning()
        {
            for(;;)
            {
                std::array<char, 50> recvData;  // 1
                //asio::streambuf buff;
                std :: string result;

                asio::ip::udp::endpoint endpoint;  // 2
                sys::error_code error;  // 3
                this->socket.get()->receive_from(asio::buffer(recvData), endpoint, 0, error);  // 4
                //std::istream(&buff) >> result;
                std::cout << recvData.begin() << std::endl;

                if (error)
                throw sys::system_error(error);  // 5
    
                std::string message{recvData.begin()};
    
                sys::error_code ec;
                this->socket.get()->send_to(boost::asio::buffer(message), endpoint, 0, ec);
            }
        }
    private:
        std::shared_ptr <asio::ip::udp::socket> socket;

};

int main()
{
    std::cout << " Hello world " << std::endl;
    UdpServer server;
    asio::io_context io;
    server.bind_socket_udp(io);
    server.start_listenning();

    return 0;
}