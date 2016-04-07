export type Device = {
    id: string;
    name: string;
    last_app: string;
    last_ip_address: string;
    last_heard: string;
    product_id: number;
    connected: boolean;
    platform_id: number;
    cellular: boolean;
    status: string;
    variables?: DeviceVariables;
}

type DeviceVariables = {
    temperature?: number;
    humidity?: number;
    lightSensor?: number;
}
