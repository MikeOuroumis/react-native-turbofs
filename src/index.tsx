import Turbofs from './NativeTurbofs';

export function readFile(path: string): Promise<string> {
  return Turbofs.readFile(path);
}

export function readDir(path: string): Promise<string[]> {
  return Turbofs.readDir(path);
}
