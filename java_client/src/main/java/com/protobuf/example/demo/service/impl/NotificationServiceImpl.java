package com.protobuf.example.demo.service.impl;

import com.protobuf.example.demo.dto.EventDto;
import com.protobuf.example.demo.exception.BusinessException;
import com.protobuf.example.demo.proto.EventsProto.Event;
import com.protobuf.example.demo.service.NotificationService;
import com.protobuf.example.demo.utils.DtoToProtoConverter;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.nio.channels.SocketChannel;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

/**
 * @author valentin.ihut
 * @since 1.0.0
 */
@Service
public class NotificationServiceImpl implements NotificationService {

  @Value("${socket.ip}")
  private String socketIp;

  @Value("${socket.port}")
  private Integer socketPort;

  @Override
  public synchronized void sendSocketMessageToServer(EventDto eventDto) throws BusinessException {
    Event protoEvent = DtoToProtoConverter.convertDtoToProto(eventDto);
    sendSocketMessage(protoEvent);
  }

  private void sendSocketMessage(Event event) throws BusinessException {
    try (Socket client = new Socket(socketIp, socketPort)) {

      // Send message to Server
      byte[] result = event.toByteArray() ;
      client.getOutputStream().write(result);

    } catch (IOException e) {
      throw new BusinessException(e.getMessage());
    }
  }

}
