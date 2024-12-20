import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  readFile(filePath: string): Promise<string>;
  readDir(filePath: string): Promise<string[]>;
}

export default TurboModuleRegistry.getEnforcing<Spec>('Turbofs');
