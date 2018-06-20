package com.protobuf.example.demo.service;

import com.protobuf.example.demo.dto.EventDto;
import com.protobuf.example.demo.exception.BusinessException;

/**
 * @author valentin.ihut
 * @since 1.0.0
 */
public interface NotificationService {

  void sendSocketMessageToServer(EventDto eventDto) throws BusinessException;
}
