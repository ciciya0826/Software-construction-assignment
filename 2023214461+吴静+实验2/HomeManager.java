import java.util.*;

public class HomeManager {
    private List<SmartDevice> devices = new ArrayList<>();

    public void addDevice(SmartDevice device) {
        devices.add(device);
        System.out.println(device.getDeviceType() + "添加成功");
    }

    public void removeDevice(String deviceId) {
        devices.removeIf(d -> d.getDeviceId().equals(deviceId));
        System.out.println(deviceId + "已移除");
    }

    public void turnOnDevice(String deviceId) {
        for (SmartDevice d : devices) {
            if (d.getDeviceId().equals(deviceId)) {
                d.turnOn();
                return;
            }
        }
        System.out.println("未找到设备" + deviceId);
    }

    public void turnOffDevice(String deviceId) {
        for (SmartDevice d : devices) {
            if (d.getDeviceId().equals(deviceId)) {
                d.turnOff();
                return;
            }
        }
        System.out.println("未找到设备" + deviceId);
    }

    public void displayAllDevices() {
        for (SmartDevice d : devices) {
            System.out.println(d.getStatus());
        }
    }
}
